# $NetBSD: Makefile,v 1.1 2013/02/21 01:13:32 lexort Exp $

DISTNAME=       diaspora-0.0.3.0
PKGNAME=        ${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=     www
MASTER_SITES=	

MAINTAINER=     gdt@NetBSD.org
HOMEPAGE=       http://diasporaproject.org/
#HOMEPAGE=	http://diaspora.github.com/diaspora/
COMMENT=        Federated privacy-aware social network
LICENSE=        gnu-agpl-v3

DEPENDS+=      redis>=3.0.2:../../wip/redis

# http://wiki.diaspora-project.org/wiki/Required_Gems_Overview

.include "../../mk/pgsql.buildlink3.mk"

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
