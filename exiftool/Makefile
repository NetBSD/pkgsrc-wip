# $NetBSD: Makefile,v 1.5 2004/09/16 23:53:06 lexort Exp $

DISTNAME=	Image-ExifTool-3.50
PKGNAME=	exiftool-3.50
CATEGORIES=	graphics perl5
MASTER_SITES=	http://owl.phy.queensu.ca/~phil/exiftool/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://owl.phy.queensu.ca/~phil/exiftool/
COMMENT=	Perl module and program to read EXIF information

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Image/ExifTool/.packlist

REPLACE_PERL=	exiftool

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
