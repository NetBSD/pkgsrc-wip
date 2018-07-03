# $NetBSD: Makefile,v 1.15 2010/07/11 12:18:55 obache Exp $

PKGNAME=	cherokee-1.2.104
GIT_COMMIT=	dad221a914fe4f3285e205d2fe6f89c393e5a705
DISTNAME=	${PKGNAME}-${GIT_COMMIT}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	-https://github.com/cherokee/webserver/archive/${GIT_COMMIT}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cherokee-project.com/
COMMENT=	Flexible and fast web server
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/webserver-${GIT_COMMIT}
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake gmake gm4 msgfmt
EXTRACT_USING=		bsdtar

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-wwwroot=${PREFIX}/share/cherokee

PKGCONFIG_OVERRIDE=	cherokee.pc.in

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}
OWN_DIRS=		${PKG_SYSCONFDIR}/cherokee
OWN_DIRS+=		${VARBASE}/log
OWN_DIRS+=		${VARBASE}/run
EGDIR=			${PREFIX}/share/examples/cherokee
MESSAGE_SUBST+=		EGDIR=${EGDIR}
CONF_FILES+=		${EGDIR}/cherokee/cherokee.conf \
			${PKG_SYSCONFDIR}/cherokee/cherokee.conf

RCD_SCRIPTS=		cherokee

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 1.2.101

.include "options.mk"

BUILD_DEFS+=		VARBASE

# this needs to be done before pre-configure
SUBST_CLASSES+=		python
SUBST_STAGE.python=	post-patch
SUBST_MESSAGE.python=	Fixing Python references
SUBST_FILES.python=	po/admin/generate_POTFILESin.py
SUBST_VARS.python=	PYTHONBIN

REPLACE_PYTHON=		admin/server.py \
			cherokee/cherokee-admin-launcher \
			cherokee/cherokee-tweak

# Needs installation:
TEST_TARGET=		test

# happens before REPLACE_PYTHON
pre-configure:
	(cd ${WRKSRC}; ${PKGSRC_SETENV} ${CONFIGURE_ENV} ${CONFIG_SHELL} ./autogen.sh)

.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
