# $NetBSD: Makefile,v 1.7 2005/04/11 21:11:56 tvierling Exp $

DISTNAME=	Image-ExifTool-3.60
PKGNAME=	exiftool-3.60
CATEGORIES=	graphics perl5
MASTER_SITES=	http://owl.phy.queensu.ca/~phil/exiftool/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://owl.phy.queensu.ca/~phil/exiftool/
COMMENT=	Perl module and program to read EXIF information

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Image/ExifTool/.packlist

REPLACE_PERL=	exiftool

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
