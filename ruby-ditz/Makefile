# $NetBSD: Makefile,v 1.3 2011/05/12 04:42:02 phonohawk Exp $
#

DISTNAME=	ditz-0.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://ditz.rubyforge.org/
COMMENT=	Simple, light-weight distributed issue tracker
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-hoe-[0-9]*:../../devel/hoe
DEPENDS+=	${RUBY_PKGPREFIX}-trollop-[0-9]*:../../wip/ruby-trollop

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
