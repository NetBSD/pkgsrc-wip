# $NetBSD: Makefile,v 1.3 2012/10/07 14:53:43 asau Exp $
#

DISTNAME=	recoll-1.17.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.lesbonscomptes.com/recoll/

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://www.lesbonscomptes.com/recoll/
COMMENT=	Full text desktop search engine
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl:run

CONFIGURE_ARGS+=	--disable-python-module
CONFIGURE_ARGS+=	--with-aspell=${BUILDLINK_PREFIX.aspell}/bin/aspell
CONFIGURE_ARGS+=	--with-file-command=${BUILDLINK_PREFIX.file}/bin/file

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

REPLACE_PERL+=		filters/rclimg

REPLACE_PYTHON+=	desktop/hotrecoll.py
REPLACE_PYTHON+=	filters/rclexecm.py
REPLACE_PYTHON+=	filters/rclaudio
REPLACE_PYTHON+=	filters/rclchm
REPLACE_PYTHON+=	filters/rcldia
REPLACE_PYTHON+=	filters/rclics
REPLACE_PYTHON+=	filters/rclinfo
REPLACE_PYTHON+=	filters/rclkar
REPLACE_PYTHON+=	filters/rcllatinclass.py
REPLACE_PYTHON+=	filters/rclpython
REPLACE_PYTHON+=	filters/rclrar
REPLACE_PYTHON+=	filters/rclwar
REPLACE_PYTHON+=	filters/rclzip

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/application.mk"
# the package installs share/applications/recoll-searchgui.desktop
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/fam/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
