# $NetBSD: Makefile,v 1.3 2011/05/15 16:10:22 thomasklausner Exp $
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

REPLACE_RUBY=	baler.rb

.include "../../lang/ruby/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
.include "../../mk/bsd.pkg.mk"
