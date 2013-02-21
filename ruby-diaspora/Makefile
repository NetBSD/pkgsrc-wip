# $NetBSD: Makefile,v 1.3 2013/02/21 01:43:43 lexort Exp $

DISTNAME=       diaspora-0.0.3.0
PKGNAME=        ${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=     www
# Diaspora is not a gem.  There is no release tarball.  Perhaps one
# can get it from github via tags, but it is not clear if that is
# stable
MASTER_SITES=	

MAINTAINER=     gdt@NetBSD.org
HOMEPAGE=       http://diasporaproject.org/
#HOMEPAGE=	http://diaspora.github.com/diaspora/
COMMENT=        Federated privacy-aware social network
LICENSE=        gnu-agpl-v3

# From the list, advice is:
#  clone https://github.com/diaspora/diaspora.git
#  it's rails, so in the clone
#    bundle && rails server

DEPENDS+=	rubygems:../../misc/rubygems
DEPENDS+=	redis>=3.0.2:../../wip/redis

# ImageMagick
# sqlite3
# git??
# bundler?
# libxml2
# libxslt
# curl
# ca_nss_root

# http://wiki.diaspora-project.org/wiki/Required_Gems_Overview

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
