# $NetBSD: Makefile,v 1.2 2003/07/04 09:50:21 jmmv Exp $
#

DISTNAME=	XML-XSH-1.6
PKGNAME=	${DISTNAME:S/XML-XSH/xsh/}
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xsh/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://xsh.sourceforge.net/
COMMENT=	XML Editing Shell

USE_PERL5=	yes
USE_GMAKE=	yes
USE_BUILDLINK2=	yes
PKG_SHELL=	${PREFIX}/bin/xsh

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
