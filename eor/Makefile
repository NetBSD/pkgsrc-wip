# $NetBSD: Makefile,v 1.5 2011/05/15 16:10:31 thomasklausner Exp $
#

DISTNAME=	eor-1.0.2
CATEGORIES=	archivers
MASTER_SITES=	http://blue.jh-inst.cas.cz/~smydke/projects/eor/releases/
EXTRACT_SUFX=	.zip

MAINTAINER=	jan.smydke@jh-inst.cas.cz
HOMEPAGE=	http://blue.jh-inst.cas.cz/~smydke/projects/eor/
COMMENT=	Exclusive OR bit operation to protect your files
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
USE_TOOLS+=	gmake

MAKE_FILE=	GNUmakefile

INSTALLATION_DIRS=	bin

.include "../../mk/bsd.pkg.mk"
