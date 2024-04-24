# $NetBSD: Makefile,v 1.4 2014/11/09 21:02:11 thomasklausner Exp $

DISTNAME=	mu-1.12.3
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=djcb/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.djcbsoftware.nl/code/mu/
COMMENT=	E-mail searching and indexing tools
LICENSE=	gnu-gpl-v3

WRKSRC=	${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
MESON_ARGS+=	-Dlispdir=${EMACS_LISPPREFIX}
MESON_ARGS+=	-Dreadline=enabled
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config autoconf automake ninja

PYTHON_FOR_BUILD_ONLY=tool
PYTHON_VERSIONS_INCOMPATIBLE=	27
# TODO: this isn't working at the moment
# REPLACE_TOOL_PYTHON=	build-aux/date.py

SUBST_CLASSES+=		py
SUBST_FILES.py=	build-aux/date.py
SUBST_STAGE.py=	post-extract
SUBST_SED.py=	-e 's,/usr/bin/env,${PREFIX}/bin/env,'
SUBST_SED.py=	-e 's,python3,python3.11,'

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && sh autogen.sh

post-install:
	-${RM} -f ${DESTDIR}${PREFIX}/info/dir

#.include "../../lang/python/application.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/readline/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../mail/gmime3/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
