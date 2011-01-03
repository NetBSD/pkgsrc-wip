# $NetBSD: Makefile,v 1.2 2011/01/03 23:26:10 thomasklausner Exp $
#

DISTNAME=	eor-1.0.1
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
USE_CMAKE=	yes

.include "../../mk/bsd.pkg.mk"
