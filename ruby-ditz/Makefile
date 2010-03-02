# $NetBSD: Makefile,v 1.1.1.1 2010/03/02 12:00:55 phonohawk Exp $
#

DISTNAME=	ditz-0.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://ditz.rubyforge.org/
COMMENT=	Simple, light-weight distributed issue tracker
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	hoe-[0-9]*:../../devel/hoe
DEPENDS+=	${RUBY_PKGPREFIX}-trollop-[0-9]*:../../wip/ruby-trollop

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
