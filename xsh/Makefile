# $NetBSD: Makefile,v 1.1.1.1 2003/07/04 03:08:46 poppnk Exp $
#

DISTNAME=	XML-XSH-${VERSION}
PKGNAME=	xsh-${VERSION}
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xsh/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://xsh.sourceforge.net/
COMMENT=	XML Editing Shell

VERSION=	1.6

USE_PERL5=	yes
USE_GMAKE=	yes
USE_BUILDLINK2=	yes
PKG_SHELL=	${PREFIX}/bin/xsh

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
