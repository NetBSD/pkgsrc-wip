# $NetBSD: Makefile,v 1.5 2014/05/09 07:38:42 thomasklausner Exp $

PKGNAME=	ditz-commander-0.4
DISTNAME=	ditz-commander_0.4.orig
CATEGORIES=	devel
MASTER_SITES=	http://ditz-commander.googlecode.com/files/

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://code.google.com/p/ditz-commander/
COMMENT=	GUI frontend for ditz the distributed issue tracker
LICENSE=	modified-bsd

DEPENDS+=	${RUBY_PKGPREFIX}-ditz>=0.5:../../wip/ruby-ditz

REPLACE_PYTHON=	ditz-commander

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-ORBit via py-gnome2, py-gtk2, py-gobject

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../lang/ruby/rubyversion.mk"
.include "../../x11/py-gnome2-extras/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
