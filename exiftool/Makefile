# $NetBSD: Makefile,v 1.1.1.1 2004/09/14 15:34:29 lexort Exp $

DISTNAME=	Image-ExifTool-3.48
PKGNAME=	exiftool-3.48
CATEGORIES=	graphics perl5
MASTER_SITES=	http://www.sno.phy.queensu.ca/~phil/exiftool/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://www.sno.phy.queensu.ca/~phil/exiftool/
COMMENT=	Perl module and program to read EXIF information

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Image/ExifTool/.packlist

REPLACE_PERL=	exiftool

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/exiftool ${PREFIX}/bin/

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
