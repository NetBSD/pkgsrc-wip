# $NetBSD: Makefile,v 1.1.1.1 2003/06/03 16:58:02 poppnk Exp $
#

DISTNAME=	MHonArc${VERSION}
PKGNAME=	mhonarc-${VERSION}
CATEGORIES=	mail
MASTER_SITES=	http://www.mhonarc.org/tar/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.mhonarc.org/
COMMENT=	perl mail-to-HTML converter

VERSION=	2.6.3

USE_BUILDLINK2=	YES
USE_PERL5=	YES
REPLACE_PERL=	${WRKSRC}/install.me

do-install:
	( cd ${WRKSRC} && ./install.me )

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
