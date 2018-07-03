# $NetBSD: Makefile,v 1.4 2014/05/09 07:38:43 thomasklausner Exp $

DISTNAME=	libinstpatch-1.0.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=swami/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://swami.sourceforge.net/
COMMENT=	Software library for editing and manipulating instrument files
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool msgfmt msgmerge perl pkg-config xgettext

PKGCONFIG_OVERRIDE+=	libinstpatch-1.0.pc.in

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-gtk2, py-gobject

.include "options.mk"

PY_PATCHPLIST=	yes

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
