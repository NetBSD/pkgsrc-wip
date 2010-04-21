# $NetBSD: Makefile,v 1.5 2010/04/21 10:07:20 fhajny Exp $
#

PKGNAME=	sphinxsearch-${PKGVERSION}
DISTNAME=	sphinx-${PKGVERSION}
PKGVERSION=	0.9.9
CATEGORIES=	databases textproc
MASTER_SITES=	http://www.sphinxsearch.com/downloads/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.sphinxsearch.com/
COMMENT=	Sphinx Full-Text Search Engine
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
BUILD_DEFS+=	VARBASE

PKG_DESTDIR_SUPPORT=	user-destdir

SPHINX_USER?=	sphinx
SPHINX_GROUP?=	sphinx
SPHINX_DIR?=	${VARBASE}/db/sphinx
SPHINX_RUN?=	${VARBASE}/spool/sphinx
SPHINX_LOG?=	${VARBASE}/log/sphinx

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

EGDIR=		${PREFIX}/share/examples/sphinx
CONF_FILES+=	${EGDIR}/sphinx-min.conf ${PKG_SYSCONFDIR}/sphinx.conf

INSTALLATION_DIRS=	bin sbin ${EGDIR}
OWN_DIRS+=		${SPHINX_DIR} ${SPHINX_RUN} ${SPHINX_LOG}
OWN_DIRS_PERMS+=	${SPHINX_DIR} ${SPHINX_USER} ${SPHINX_GROUP} 0770
OWN_DIRS_PERMS+=	${SPHINX_RUN} ${SPHINX_USER} ${SPHINX_GROUP} 0770
OWN_DIRS_PERMS+=	${SPHINX_LOG} ${SPHINX_USER} ${SPHINX_GROUP} 0770

PKG_GROUPS+=		${SPHINX_GROUP}
PKG_USERS+=		${SPHINX_USER}:${SPHINX_GROUP}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting standard paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	sphinx.conf.in sphinx-min.conf.in Makefile.in
SUBST_SED.paths+=	-e 's,@CONFDIR@/log/searchd.pid,${SPHINX_RUN}/searchd.pid,g'
SUBST_SED.paths+=	-e 's,@CONFDIR@/log/query.log,${SPHINX_LOG}/query.log,g'
SUBST_SED.paths+=	-e 's,@CONFDIR@/log/searchd.log,${SPHINX_LOG}/searchd.log,g'
SUBST_SED.paths+=	-e 's,@CONFDIR@,${SPHINX_DIR},g'
SUBST_SED.paths+=	-e 's,@localstatedir@,${SPHINX_DIR},g'
SUBST_SED.paths+=	-e 's,@egdir@,${EGDIR},g'

CONFIGURE_DIRS=		.
CONFIGURE_DIRS+=	api/libsphinxclient

LDFLAGS.SunOS+=		-lsocket -lnsl

post-install:
	${MV} ${DESTDIR}${EGDIR}/sphinx.conf.dist ${DESTDIR}${EGDIR}/sphinx-full.conf
	${MV} ${DESTDIR}${EGDIR}/sphinx-min.conf.dist ${DESTDIR}${EGDIR}/sphinx-min.conf

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
