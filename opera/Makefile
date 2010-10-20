# $NetBSD: Makefile,v 1.9 2010/10/20 13:02:34 obache Exp $

DISTNAME=		opera-${OPERA_PKG_VERSION}-${OPERA_PKG_BUILD}.${OPERA_ARCH}.${EMUL_OPSYS}
PKGNAME=		opera-${OPERA_PKG_VERSION:S/u/pl/}
CATEGORIES=		www
MASTER_SITES+=		${MASTER_SITE_OPERA:=${OPERA_DIR}/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.opera.com/
COMMENT=		Small, fast and customizable WWW client
LICENSE=		opera-1000-license
LICENSE_FILE=		opera-1000-license

EMUL_PLATFORMS=		freebsd-i386 freebsd-x86_64
EMUL_PLATFORMS+=	linux-i386 linux-x86_64 linux-powerpc

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

MASTER_SITE_OPERA+=	ftp://get.opera.com/pub/opera/
MASTER_SITE_OPERA+=	http://ftp.sunet.se/pub/www/clients/Opera/
MASTER_SITE_OPERA+=	ftp://ftp.hu-berlin.de/pub/www/opera/
MASTER_SITE_OPERA+=	ftp://ftp.task.gda.pl/pub/opera/
MASTER_SITE_OPERA+=	ftp://ftp.tuwien.ac.at/infosys/browsers/opera/
MASTER_SITE_OPERA+=	ftp://opera.nsc.no/pub/nsc.no/mirrors/operasoftware/
MASTER_SITE_OPERA+=	ftp://ftp.opera.com/pub/opera/
MASTER_SITE_OPERA+=	http://ftp.yz.yamagata-u.ac.jp/pub/opera/

USE_LANGUAGES=		# empty
NO_BUILD=		yes

OPERA_PKG_BUILD=	6450
OPERA_PKG_VERSION=	10.63
OPERA_PKG_VERSION_DIR=	1063

.if ${EMUL_OPSYS} == "linux"
EMUL_MODULES.linux=	gtk2 xml2
# need gstreamer0.10
#EMUL_MODULES.linux+=	xml2 gstreamer
EMUL_REQD=		suse>=10.0
OPERA_ARCH.x86_64=	x86_64
OPERA_ARCH.powerpc=	ppc
OPERA_OPSYS_SUBDIR=	linux
.if !defined(EMUL_IS_NATIVE) && ${OPSYS} == "NetBSD"
TOOLS_CREATE+=		md5
TOOLS_SCRIPT.md5=	/usr/bin/md5 -n "$$2" | { read sum file; echo $$sum; }
.endif

.elif ${EMUL_OPSYS} == "freebsd"
OPERA_ARCH.x86_64=	amd64
OPERA_OPSYS_SUBDIR=	unix
.endif
OPERA_ARCH=		${OPERA_ARCH.${EMUL_ARCH}:U${EMUL_ARCH}}
OPERA_DIR=		${OPERA_OPSYS_SUBDIR}/${OPERA_PKG_VERSION_DIR}

MANCOMPRESSED=		yes

SUBST_CLASSES+=		plugin
SUBST_STAGE.plugin=	post-install
SUBST_FILES.plugin=	${DESTDIR}${PREFIX}/share/opera/defaults/pluginpath.ini
SUBST_SED.plugin=	-e 's,/usr/local/,${PREFIX}/,g'

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-extract
SUBST_FILES.prefix=	install
SUBST_SED.prefix=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.prefix+=	-e 's,dest=,dest=${DESTDIR},g'

.if ${PKGMANDIR} != "share/man"
post-extract:
	${RUN} cd ${WRKSRC}; mv share/man ${PKGMANDIR}

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	post-extract
SUBST_FILES.manpath=	install
SUBST_SED.manpath=	-e 's,share/man,${PKGMANDIR},g'
.endif

do-install:
	${RUN} cd ${WRKSRC};				\
		${SH} ./install --text --unattended --quiet --system --force

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
