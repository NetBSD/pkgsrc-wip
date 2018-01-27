# $NetBSD: Makefile,v 1.13 2015/03/07 18:22:04 ishit Exp $

DISTNAME=	mathopd-1.6b15
CATEGORIES=	www
MASTER_SITES=	http://www.mathopd.org/dist/

MAINTAINER=	ishit@users.sourceforge.net
HOMEPAGE=	http://www.mathopd.org/
COMMENT=	Very small, yet very fast HTTP server

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}/${DISTNAME}/src

MATHOPD_USER?=		mathopd
MATHOPD_GROUP?=		mathopd
MATHOPD_DOCDIR?=	${PREFIX}/share/doc/mathopd
MATHOPD_LOGDIR?=	${VARBASE}/log/mathopd
MATHOPD_PIDDIR?=	${VARBASE}/run

BUILD_DEFS=	VARBASE MATHOPD_DOCDIR MATHOPD_LOGDIR MATHOPD_PIDDIR

PKG_USERS_VARS+=	MATHOPD_USER
PKG_GROUPS_VARS+=	MATHOPD_GROUP
PKG_GROUPS=		${MATHOPD_GROUP}
PKG_USERS=		${MATHOPD_USER}:${MATHOPD_GROUP}

PKG_GECOS.${MATHOPD_USER}=	mathopd server user
#PKG_HOME.${MATHOPD_USER}=
PKG_SHELL.${MATHOPD_USER}=	${NOLOGIN}

USE_PKGLOCALEDIR=	yes

EGDIR=		${PREFIX}/share/examples/mathopd
CONF_FILES=	${EGDIR}/mathopd.conf ${PKG_SYSCONFDIR}/mathopd.conf
RCD_SCRIPTS=	mathopd

INSTALLATION_DIRS=	sbin share/examples/mathopd share/doc/mathopd
MAKE_DIRS+=		${MATHOPD_PIDDIR}
OWN_DIRS=		${MATHOPD_LOGDIR}
#OWN_DIRS_PERMS+=	${MATHOPD_LOGDIR} ${MATHOPD_USER} ${MATHOPD_GROUP} 0755

DOCS=	CHANGES cgi.txt config.txt running.txt sample.cfg syntax.txt

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		Makefile
SUBST_FILES.fix-paths+=		../doc/sample.cfg
SUBST_SED.fix-paths=		-e 's,/usr/local,${PREFIX},g'
SUBST_SED.fix-paths+=		-e 's,/var/mathopd/pid,${MATHOPD_PIDDIR}/mathopd.pid,g'
SUBST_SED.fix-paths+=		-e 's,/var/mathopd/log,${MATHOPD_LOGDIR}/mathopd/access_log,g'
SUBST_SED.fix-paths+=		-e 's,/var/mathopd/errorlog,${MATHOPD_LOGDIR}/mathopd/error_log,g'
SUBST_SED.fix-paths+=		-e 's,/var/mathopd/childlog,${MATHOPD_LOGDIR}/mathopd/child_log,g'
SUBST_SED.fix-paths+=		-e 's,/home/boland/\*,${PREFIX}/share/httpd/htdocs/\*,g'
SUBST_SED.fix-paths+=		-e 's,/home/boland/cgi-bin,${PREFIX}/libexec/cgi-bin,g'

.if ${OPSYS} == "NetBSD"
CPPFLAGS+=	-DHAVE_VFORK
.endif

.if ${OPSYS} == "Linux"
BUILD_DEFS+=	EXTRA_OBJS
CPPFLAGS+=	-DHAVE_CRYPT_H
CPPFLAGS+=	-DLINUX_SENDFILE
CPPFLAGS+=	-D_FILE_OFFSET_BITS=64
EXTRA_OBJS+=	sendfile.o
.endif

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
BUILD_DEFS+=	EXTRA_OBJS
CPPFLAGS+=	-DFREEBSD_SENDFILE
EXTRA_OBJS+=	sendfile.o
.endif

.if ${OPSYS} == "SunOS"
CPPFLAGS+=	-D_FILE_OFFSET_BITS=64
CPPFLAGS+=	-DHAVE_CRYPT_H
.endif

pre-configure:
.if ${OPSYS} == "SunOS"
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.patched
	${SED} -e 's!LIBS = -lcrypt!LIBS = -lsocket -lnsl -lresolv!' \
	< ${WRKSRC}/Makefile.patched \
	> ${WRKSRC}/Makefile
.endif

#pre-install:
#	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
#	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/sample.cfg ${DESTDIR}${EGDIR}/mathopd.conf
	#${MV} ${DESTDIR}${EGDIR}/sample.cfg ${DESTDIR}${EGDIR}

	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/COPYING ${DESTDIR}${MATHOPD_DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README  ${DESTDIR}${MATHOPD_DOCDIR}
	for df in ${DOCS}; do	\
		${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/$${df} ${DESTDIR}${MATHOPD_DOCDIR};	\
	done

#	${TOUCH} ${DESTDIR}${VARBASE}/run/mathopd.pid
#	${CHOWN} ${MATHOPD_USER}:${MATHOPD_GROUP} ${DESTDIR}${MATHOPD_PIDDIR}/mathopd.pid

.include "../../mk/bsd.pkg.mk"
