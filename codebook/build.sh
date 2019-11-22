#!/bin/bash

export PATH=/usr/local/texlive/2019/bin/x86_64-linux:$PATH
texliveonfly codebook.tex --compiler=xelatex
latexmk -pdfxe codebook.tex