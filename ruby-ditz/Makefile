# $NetBSD: Makefile,v 1.2 2010/11/13 00:10:56 cheusov Exp $
#

DISTNAME=	ditz-0.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://ditz.rubyforge.org/
COMMENT=	Simple, light-weight distributed issue tracker
LICENSE=	gnu-gpl-v3

BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-hoe-[0-9]*:../../devel/hoe
DEPENDS+=	${RUBY_PKGPREFIX}-trollop-[0-9]*:../../wip/ruby-trollop

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
