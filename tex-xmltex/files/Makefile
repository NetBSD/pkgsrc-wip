# $NetBSD: Makefile,v 1.1.1.1 2003/10/11 21:45:01 minskim Exp $

all: xmltex.fmt pdfxmltex.fmt

xmltex.fmt:
	tex -ini -progname=xmltex "&latex" xmltex.ini

pdfxmltex.fmt:
	pdftex -ini -progname=pdfxmltex "&pdflatex" pdfxmltex.ini
