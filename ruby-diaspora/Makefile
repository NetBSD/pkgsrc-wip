# $NetBSD: Makefile,v 1.9 2013/06/14 07:36:56 thomasklausner Exp $

DISTNAME=	diaspora-0.0.3.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	www
# Diaspora is not a gem.  There is no release tarball.  Perhaps one
# can get it from github via tags, but it is not clear if that is
# stable
MASTER_SITES=	

# For now, obtain dependencies only.
META_PACKAGE=	yes

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://diasporaproject.org/
#HOMEPAGE=	http://diaspora.github.com/diaspora/
COMMENT=	Federated privacy-aware social network
LICENSE=	gnu-agpl-v3

# Packaging decisions:
#   This package will only (for now) support pgsql.

# main install instructions:
#   https://github.com/diaspora/diaspora/wiki/Notes-on-Installing-and-Running-Diaspora
# manual starting instructions:
#   https://github.com/diaspora/diaspora/wiki/Run-Diasporas-Components

#do-build:
#  export DB=postgres
#  bundle --path=vendor
#  !! change pgsql template encoding to utf-8 from sqlascii
#  bundle exec rake db:create
#  rake db:schema:load

#rc.d/diaspora fodder:
#   rails server

# See script/install.sh

# http://wiki.diaspora-project.org/wiki/Installing_on_FreeBSD
# http://wiki.debian.org/Diaspora/Packaging?action=show&redirect=Diaspora%2Fpackaging

# diaspora hints (perhaps for post-install script)
# https://github.com/diaspora/diaspora/wiki/FAQ-for-Developers
# https://github.com/diaspora/diaspora/wiki/FAQ-for-Pod-Maintainers

# rails hints
# http://guides.rubyonrails.org/getting_started.html

DEPENDS+=	${RUBY_PKGPREFIX}-rubygems-[0-9]*:../../misc/rubygems
DEPENDS+=	${RUBY_PKGPREFIX}-bundler-[0-9]*:../../misc/ruby-bundler

# TODO: package and depend on all required gems:
# http://wiki.diaspora-project.org/wiki/Required_Gems_Overview

# Confusing, there is a redis ruby gem at 3.0.3, but that's a
# different versioning space.  As of 20130306, the latest redis stable
# was 2.6.10, so assume without basis that 2.6.9 is good enough.
DEPENDS+=	redis>=2.6.9:../../databases/redis

# Items listed as a depedency someplace, to be checked:
# sqlite3
# libxml2
# libxslt
# curl
# ca_nss_root

# There is a notion that git is required, but it's not clear if that's
# just for getting the source.

BUILD_ENV+=	"DB=postgres"
.include "../../mk/pgsql.buildlink3.mk"
# Someone could add an option to use mysql instead of pgsql.
# .include "../../mk/mysql.buildlink3.mk"

# A required gem wraps imagemagick.
.include "../../graphics/ImageMagick/buildlink3.mk"

# TODO: figure out how to depend on rails
# RUBY_RAILS_SUPPORTED=	32
#.include "../../lang/ruby/rubyversion.mk"
#.include "../../lang/ruby/rails.mk"

# This package runs ruby.
.include "../../lang/ruby/modules.mk"

.include "../../mk/bsd.pkg.mk"
