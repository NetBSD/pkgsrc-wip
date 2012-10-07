# $NetBSD: Makefile,v 1.4 2012/10/07 17:17:49 asau Exp $

DISTNAME=	tscreen-0.4.9
CATEGORIES=	misc shells
MASTER_SITES=	http://www.steve.org.uk/Software/tscreen/dist/

MAINTAINER=	ishit@users.sourceforge.jp
HOMEPAGE=	http://www.steve.org.uk/Software/tscreen/
COMMENT=	Multi-screen window manager
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "options.mk"

NOT_FOR_PLATFORM=	Interix-*-* # user auth and username size fixes needed

PLIST_SUBST+=		DISTNAME=${DISTNAME:Q}

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-telnet

PKG_SHELL=		bin/tscreen
INFO_FILES=		YES

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	etc/etcscreenrc doc/screen.1
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,@EXAMPLES@,${PREFIX}/share/examples/tscreen,g'
SUBST_STAGE.paths=	post-patch

PLIST_VARS+=		terminfo
.if (${OPSYS} == "SunOS") && exists(/usr/5bin/tic)
INSTALLATION_DIRS+=	share/lib/terminfo
PLIST.terminfo=		yes
post-install: screen-terminfo
.endif

.if empty(UNPRIVILEGED:M[Yy][Ee][Ss])
SPECIAL_PERMS+=		bin/${DISTNAME} ${SETUID_ROOT_PERMS}
.endif

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/tscreen
	${INSTALL_DATA} ${WRKSRC}/etc/etcscreenrc			\
		${DESTDIR}${PREFIX}/share/examples/tscreen/etcscreenrc
	${INSTALL_DATA} ${WRKSRC}/etc/tscreenrc				\
		${DESTDIR}${PREFIX}/share/examples/tscreen/tscreenrc
.if !empty(UNPRIVILEGED:M[Yy][Ee][Ss])
	chmod -s ${DESTDIR}${PREFIX}/bin/${DISTNAME}
.endif

.PHONY: screen-terminfo
screen-terminfo:
	cd ${WRKSRC}/terminfo &&					\
	${SETENV} TERMINFO=${DESTDIR}${PREFIX}/share/lib/terminfo	\
		/usr/5bin/tic screeninfo.src

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
