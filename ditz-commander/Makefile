# $NetBSD: Makefile,v 1.1.1.1 2011/03/18 05:39:35 phonohawk Exp $
#

PKGNAME=	ditz-commander-0.4
DISTNAME=	ditz-commander_0.4.orig
CATEGORIES=	devel
MASTER_SITES=	http://ditz-commander.googlecode.com/files/

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://code.google.com/p/ditz-commander/
COMMENT=	GUI frontend for ditz the distributed issue tracker
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_PYTHON=	ditz-commander

DEPENDS+=	${RUBY_PKGPREFIX}-ditz>=0.5:../../wip/ruby-ditz
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../lang/ruby/rubyversion.mk"
.include "../../x11/py-gnome2-extras/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
