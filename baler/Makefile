# $NetBSD: Makefile,v 1.1.1.1 2010/12/31 16:24:38 crocusino Exp $
#

DISTNAME=	baler-1.0
CATEGORIES=	archivers
MASTER_SITES=	http://blue.jh-inst.cas.cz/~smydke/projects/baler/releases/
EXTRACT_SUFX=	.zip

MAINTAINER=	jan.smydke@jh-inst.cas.cz
HOMEPAGE=	http://blue.jh-inst.cas.cz/~smydke/projects/baler
COMMENT=	Store data in bales and provide a TOC for direct access

LICENSE=	2-clause-bsd

DEPENDS+=	ruby:../../lang/ruby

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile

NO_BUILD=	yes

.include "../../mk/bsd.pkg.mk"
