# $NetBSD: Makefile,v 1.1.1.1 2009/09/02 19:31:26 yuripoloni Exp $
#

DISTNAME=	actionmessenger-0.2.0
PKGNAME=        ${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	chat
MASTER_SITES=	http://trypticon.org/files/software/actionmessenger/
EXTRACT_SUFX=	.gem

MAINTAINER=	yuripoloni@gmail.com
HOMEPAGE=	http://trypticon.org/software/actionmessenger/
COMMENT=	Ruby convenience framework for instant messaging
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

GEM_BUILD=      gemspec
USE_LANGUAGES=	# none

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
