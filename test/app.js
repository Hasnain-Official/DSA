const { PDFDocument } = require('pdf-lib');
const fs = require('fs');
const { error, log } = require('console');

const file1Path = './1.pdf';
const file2Path = './2.pdf';

async function extractLinesFromPDF(pdf) {
    let lines = [];
    for (let i = 1; i <= pdf.numPages; i++) {
        const page = await pdf.getPage(i);
        const content = await page.getTextContent();
        content.items.forEach(item => {
            lines.push(item.str);
        });
    }
    return lines;
}

function compareLines(lines1, lines2) {
    if (lines1.length !== lines2.length) {
        return false;
    }
    for (let i = 0; i < lines1.length; i++) {
        if (lines1[i] !== lines2[i]) {
            return false;
        }
    }
    return true;
}

function getDifferentLines(lines1, lines2) {
    const diffLines = [];
    let count = 0;
    for (let i = 0; i < lines1.length; i++) {
        if (lines1[i] !== lines2[i]) {
            diffLines.push({ line1: lines1[i], line2: lines2[i] });
            count++;
        }
    }
    return {lines : diffLines, count : count};
}

async function pdfjsLoader(fileData) {
    const pdfjs = await import('pdfjs-dist');
    const loadingTask = pdfjs.getDocument({ data: new Uint8Array(fileData) });
    return loadingTask.promise;
}

(async function comparePDF() {
try {    
    const [file1Exists, file2Exists] = await Promise.all([
        Promise.resolve(fs.existsSync(file1Path)),
        Promise.resolve(fs.existsSync(file2Path))
    ]);
    if(file1Exists && file2Exists) {    
        const [fileBytes1, fileBytes2] = await Promise.all([
            Promise.resolve(fs.readFileSync(file1Path)),
            Promise.resolve(fs.readFileSync(file2Path))
        ]);
        if(fileBytes1 && fileBytes2) {
            const pdf1 = await pdfjsLoader(fileBytes1);
            const pdf2 = await pdfjsLoader(fileBytes2);
            const lines1 = await extractLinesFromPDF(pdf1);
            const lines2 = await extractLinesFromPDF(pdf2);

            const areEqual = compareLines(lines1, lines2);

            if(areEqual) {
                log("Files  are identical.");
            } else {
                log("Files are different.");
                const diffLines = getDifferentLines(lines1, lines2);
                // log("Difference in Lines - ", diffLines?.lines);
                log("Difference of Lines - ", diffLines?.count);
            }
        } else {
            log("Something's not right while reading files.");
        }
    } else {
        log(`File not found, please check.`);
    }
} catch(err) {
    error(`Something went wrong! - `, err);
}
})();