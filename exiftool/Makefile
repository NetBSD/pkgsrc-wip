# $NetBSD: Makefile,v 1.8 2005/04/20 17:02:40 lexort Exp $

DISTNAME=	Image-ExifTool-${VERSION}
PKGNAME=	exiftool-${VERSION}
CATEGORIES=	graphics perl5
MASTER_SITES=	http://owl.phy.queensu.ca/~phil/exiftool/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://owl.phy.queensu.ca/~phil/exiftool/
COMMENT=	Perl module and program to read EXIF information

VERSION=	4.93

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Image/ExifTool/.packlist

REPLACE_PERL=	exiftool

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
