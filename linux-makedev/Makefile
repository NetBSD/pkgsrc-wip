# $NetBSD: Makefile,v 1.3 2004/04/09 20:22:46 jeremy-c-reed Exp $
#

DISTNAME=		makedev_2.3.1.orig
PKGNAME=		linux-makedev-${VERSION:S/-/./}
WRKSRC=			${WRKDIR}/makedev-2.3.1.orig
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_DEBIAN:=pool/main/m/makedev/}

PATCH_SITES=		${MASTER_SITE_DEBIAN:=pool/main/m/makedev/}
PATCHFILES=		makedev_${VERSION}.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		reed@reedmedia.net
COMMENT=		Script to make and update Linux /dev device nodes

ONLY_FOR_PLATFORM=	Linux-*-* # This is for the Linux kernel devices

VERSION=		2.3.1-66

NO_CONFIGURE=		YES
NO_BUILD=		YES

USE_PKGINSTALL=		YES
# XXX maybe should not hard-code group numbers; does it matter?
#PKG_GROUPS=		daemon:1 sys:3 tty:5 disk:6 uucp:10 kmem:15 floppy:25
PKG_GROUPS=		root daemon sys tty disk uucp kmem floppy
PKG_GROUPS+=		dialout dip lp disk cdrom tape audio video

post-patch:
	${SED} -e 's,@VERSION@,${VERSION},g' < ${WRKSRC}/MAKEDEV \
		> ${WRKSRC}/MAKEDEV.tmp \
		&& ${MV} ${WRKSRC}/MAKEDEV.tmp ${WRKSRC}/MAKEDEV

do-install:
	${INSTALL_MAN} ${WRKSRC}/MAKEDEV.man ${PREFIX}/man/man8/MAKEDEV.8
	${INSTALL_SCRIPT} ${WRKSRC}/MAKEDEV ${PREFIX}/sbin/

.include "../../mk/bsd.pkg.mk"
