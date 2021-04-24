# $NetBSD: Makefile,v 1.2 2012/10/03 21:02:10 asau Exp $

PKGNAME=	openbgpd-as4byte-3.9
DISTNAME=	openbgpd
VERSION=	3.9
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://cdn.openbsd.org/pub/OpenBSD/OpenBGPD/
DISTFILES?=	${DISTNAME}-${VERSION}.tgz
DISTFILES+=	if_media.h pfkey_compat.c hash.h strtonum.c
DIST_SUBDIR=	openbgpd
EXTRACT_ONLY=	${DISTNAME}-${VERSION}.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openbgp.org/
COMMENT=	Free implementation of the Border Gateway Protocol, Version 4

CONFLICTS=	zebra-0* quagga-0* openbgpd-3*

WRKSRC=		${WRKDIR}
MANCOMPRESSED=	yes
USE_RC_SUBR=	openbgpd.sh
#MAKE_ENV=	BINDIR="${PREFIX}/sbin" \
#		MANDIR="${PREFIX}/man"
COPTS+=		-DRTA_LABEL=0

#PLIST_FILES=	sbin/bgpctl	\
#		sbin/bgpd \
#		man/man8/bgpd.8 \
#		man/man5/bgpd.conf.5 \
#		man/man8/bgpctl.8

SUBDIRS=	bgpd \
		bgpctl

.include "../../mk/bsd.prefs.mk"

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/if_media.h ${WRKSRC}/bgpctl/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/pfkey_compat.c ${WRKSRC}/bgpd/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/hash.h ${WRKSRC}/bgpd/
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/strtonum.c ${WRKSRC}/bgpctl/

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		post-patch
SUBST_MESSAGE.fix-paths=	fixing absolute paths
SUBST_FILES.fix-paths=		bgpd/Makefile
SUBST_FILES.fix-paths+=		bgpd/bgpd.8
SUBST_FILES.fix-paths+=		bgpd/bgpd.h
SUBST_FILES.fix-paths+=		bgpd/bgpd.conf.5
SUBST_FILES.fix-paths+=		bgpctl/Makefile
SUBST_FILES.fix-paths+=		bgpctl/bgpctl.8
SUBST_SED.fix-paths=		-e 's,%%PREFIX%%,${PREFIX},g'

SUBST_CLASSES+=			undead
SUBST_STAGE.undead=		post-patch
SUBST_MESSAGE.undead=		remove __dead references
SUBST_FILES.undead=		bgpd/bgpd.c
SUBST_FILES.undead+=		bgpd/bgpd.h
SUBST_FILES.undead+=		bgpctl/bgpctl.c
SUBST_SED.undead=		-e 's,__dead,,'

SUBST_CLASSES+=			stailq
SUBST_STAGE.stailq=		post-patch
SUBST_MESSAGE.stailq=		convert to tailq
SUBST_FILES.stailq=		bgpd/*.[chy]
SUBST_SED.stailq=		-e 's,SIMPLEQ,STAILQ,'

SUBST_CLASSES+=			ifmedia
SUBST_STAGE.ifmedia=		post-patch
SUBST_MESSAGE.ifmedia=		convert if_media.h
SUBST_FILES.ifmedia=		bgpctl/bgpctl.c
SUBST_SED.ifmedia=		-e 's,<net/if_media.h>,\"if_media.h\",'

SUBST_CLASSES+=			pfkey
SUBST_STAGE.pfkey=		post-patch
SUBST_MESSAGE.pfkey=		convert pfkey to pfkey_compat
SUBST_FILES.pfkey=		bgpd/Makefile
SUBST_SED.pfkey=		-e 's,pfkey.c,pfkey_compat.c,'

SUBST_CLASSES+=			hash
SUBST_STAGE.hash=		post-patch
SUBST_MESSAGE.hash=		convert sys/hash.h to hash.h
SUBST_FILES.hash=		bgpd/rde_attr.c
SUBST_FILES.hash+=		bgpd/rde_rib.c
SUBST_FILES.hash+=		bgpd/rde_update.c
SUBST_SED.hash=			-e 's,sys/hash.h,hash.h,'

SUBST_CLASSES+=			rtm
SUBST_STAGE.rtm=		post-patch
SUBST_MESSAGE.rtm=		convert rtm_fmask to rtm_use
SUBST_FILES.rtm=		bgpd/kroute.c
SUBST_SED.rtm=			-e 's,rtm_fmask,rtm_use,'

SUBST_CLASSES+=			rtlabel
SUBST_STAGE.rtlabel=		post-patch
SUBST_MESSAGE.rtlabel=		convert RTLABEL_LEN to PFTABLE_LEN
SUBST_FILES.rtlabel=		bgpd/bgpd.h
SUBST_SED.rtlabel=		-e 's,RTLABEL_LEN,PFTABLE_LEN,'

do-build:
.for i in ${SUBDIRS}
	cd ${WRKSRC}/$i; make COPTS="${COPTS}"
.endfor

post-install:
	@echo "yep"

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bgpd/bgpd ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/bgpctl/bgpctl ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/bgpd/bgpd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/bgpd/bgpd.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKSRC}/bgpctl/bgpctl.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
