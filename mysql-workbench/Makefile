# $NetBSD: Makefile,v 1.2 2010/04/15 21:42:11 othyro Exp $
#

PKGVERSION=	5.2.18
DISTNAME=	mysql-workbench-oss-${PKGVERSION}
PKGNAME=	${DISTNAME:S/-oss//}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL:=MySQLGUITools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wb.mysql.com/
COMMENT=	Cross-platform, visual database design tool
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++ fortran
USE_TOOLS+=		aclocal autoconf automake autoreconf
USE_LIBTOOL=		yes

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python=	configure configure.in
SUBST_SED.python=	-e "s,python -c,${PYTHONBIN} -c,g"
SUBST_MESSAGE.python=	Fixing hardcoded python binary

.include "../../archivers/libzip/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../wip/libuuid/buildlink3.mk"
.include "../../databases/mysql5-client/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
