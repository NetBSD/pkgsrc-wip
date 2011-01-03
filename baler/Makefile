# $NetBSD: Makefile,v 1.2 2011/01/03 23:24:38 thomasklausner Exp $
#

DISTNAME=	baler-1.0
CATEGORIES=	archivers
MASTER_SITES=	http://blue.jh-inst.cas.cz/~smydke/projects/baler/releases/
EXTRACT_SUFX=	.zip

MAINTAINER=	jan.smydke@jh-inst.cas.cz
HOMEPAGE=	http://blue.jh-inst.cas.cz/~smydke/projects/baler
COMMENT=	Store data in bales and provide a TOC for direct access
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile

NO_BUILD=	yes

.include "../../lang/ruby/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
