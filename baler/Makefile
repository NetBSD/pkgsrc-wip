# $NetBSD: Makefile,v 1.4 2012/09/24 17:14:26 asau Exp $
#

DISTNAME=	baler-1.0
CATEGORIES=	archivers
MASTER_SITES=	http://blue.jh-inst.cas.cz/~smydke/projects/baler/releases/
EXTRACT_SUFX=	.zip

MAINTAINER=	jan.smydke@jh-inst.cas.cz
HOMEPAGE=	http://blue.jh-inst.cas.cz/~smydke/projects/baler
COMMENT=	Store data in bales and provide a TOC for direct access
LICENSE=	2-clause-bsd

USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile

NO_BUILD=	yes

REPLACE_RUBY=	baler.rb

.include "../../lang/ruby/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
.include "../../mk/bsd.pkg.mk"
