# $NetBSD: Makefile,v 1.2 2013/02/21 01:28:09 lexort Exp $

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

# Diaspora is not a gem.  There are no release tarballs.
# From the list, advice is:
#  clone https://github.com/diaspora/diaspora.git
#  it's rails, so in the clone
#    bundle && rails server

.include "../../mk/pgsql.buildlink3.mk"

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
