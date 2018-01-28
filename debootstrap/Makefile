# $NetBSD$

DISTNAME=			debootstrap_1.0.90
PKGNAME=			${DISTNAME:S/_/-/}
CATEGORIES=			sysutils emulators
MASTER_SITES=			${MASTER_SITE_DEBIAN:=pool/main/d/debootstrap/}
DISTFILES=			${DEFAULT_DISTFILES} ${DEBIAN_KEYRING_DEB} ${UBUNTU_KEYRING_DEB}
DEBIAN_KEYRING_DEB=		debian-archive-keyring_2014.3_all.deb
UBUNTU_KEYRING_DEB=		ubuntu-archive-keyring_2012.05.19-1_all.deb
SITES.${DEBIAN_KEYRING_DEB}=	${MASTER_SITE_DEBIAN:=pool/main/d/debian-archive-keyring/}
SITES.${UBUNTU_KEYRING_DEB}=	${MASTER_SITE_DEBIAN:=pool/main/u/ubuntu-keyring/}

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://wiki.debian.org/Debootstrap
COMMENT=	Debian GNU/Linux (and Ubuntu) cross-bootstrapping utility
LICENSE=	mit

DEPENDS+=	wget-[0-9]*:../../net/wget
DEPENDS+=	gnupg-[0-9]*:../../security/gnupg
DEPENDS+=	coreutils-[0-9]*:../../sysutils/coreutils

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
#WRKSRC=	${WRKDIR}/debootstrap.git
USE_LANGUAGES=	# none

USE_TOOLS+=	gmake xzcat tar bash:run

CHECK_SHLIBS_SKIP=	share/debootstrap/libfakesyscall-i386.so	\
			share/debootstrap/libfakesyscall-amd64.so

REPLACE_BASH=	debootstrap

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		Makefile
SUBST_SED.fix-paths=		-e 's,/usr/,${PREFIX}/,g'

SUBST_CLASSES+=			fix-paths2
SUBST_STAGE.fix-paths2=		pre-configure
SUBST_MESSAGE.fix-paths2=	Fixing absolute paths.
SUBST_FILES.fix-paths2=		debootstrap
SUBST_SED.fix-paths2=		-e 's,@PREFIX@,${PREFIX},g'

SUBST_CLASSES+=			fix-paths3
SUBST_STAGE.fix-paths3=		pre-configure
SUBST_MESSAGE.fix-paths3=	Fixing absolute paths.
SUBST_FILES.fix-paths3=		scripts/*
# Provide a dummy /sbin/init
SUBST_SED.fix-paths3=		-e 's,mv "$$TARGET/sbin/start-stop-daemon" "$$TARGET/sbin/start-stop-daemon.REAL",mv "$$TARGET/sbin/init" "$$TARGET/sbin/init.REAL"; ln -s /bin/true "$$TARGET/sbin/init"; &,g'
SUBST_SED.fix-paths3+=		-e 's,/usr/share/keyrings,${PREFIX}/share/debootstrap,g'

.include "../../mk/bsd.prefs.mk"

# XXX devices.tar.gz generation stuff needs root on Linux
.if ${OPSYS} == "Linux"
PKG_DESTDIR_SUPPORT=	destdir
NOT_FOR_UNPRIVILEGED=	yes
.endif

post-extract:
.for keyring_deb in ${DEBIAN_KEYRING_DEB} ${UBUNTU_KEYRING_DEB}
	cd ${WRKDIR} && ar x ${keyring_deb}
	mkdir ${WRKDIR}/${keyring_deb:S/.deb//}
	cd ${WRKDIR}/${keyring_deb:S/.deb//} && ${XZCAT} ../data.tar.xz | ${TAR} xf -
.endfor
	cp ${FILESDIR}/[a-z]* ${WRKDIR}
	set -e; cd ${WRKDIR}; for uue in *.uue; do uudecode $$uue; done

post-build:
	rm -f ${WRKSRC}/scripts/*.orig

post-install:
	${INSTALL_DATA} ${WRKDIR}/${DEBIAN_KEYRING_DEB:S/.deb//}/usr/share/keyrings/debian-archive-keyring.gpg ${DESTDIR}${PREFIX}/share/debootstrap/debian-archive-keyring.gpg
	${INSTALL_DATA} ${WRKDIR}/${UBUNTU_KEYRING_DEB:S/.deb//}/usr/share/keyrings/ubuntu-archive-keyring.gpg ${DESTDIR}${PREFIX}/share/debootstrap/ubuntu-archive-keyring.gpg
.for f in libfakesyscall-i386.so libfakesyscall-amd64.so libfakesyscall.c
	${INSTALL_DATA} ${WRKDIR}/${f} ${DESTDIR}${PREFIX}/share/debootstrap/${f}
.endfor
.if ${OPSYS} == "NetBSD"
	${INSTALL_DATA} ${WRKDIR}/devices.tar.gz ${DESTDIR}${PREFIX}/share/debootstrap/devices.tar.gz
.endif

.include "../../mk/bsd.pkg.mk"
