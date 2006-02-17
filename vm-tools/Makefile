# $NetBSD: Makefile,v 1.5 2006/02/17 09:30:57 marttikuparinen Exp $
#

DISTNAME=		vm-tools-0.1.9
CATEGORIES=		sysutils
MASTER_SITES=		http://www.cs.utexas.edu/users/aliguori/vm-tools/

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://www.cs.utexas.edu/users/aliguori/vm-tools/
COMMENT=		Lightweight management framework for Xen

ONLY_FOR_PLATFORM=	NetBSD-*-i386

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

pre-build:
	${MKDIR} ${BUILDLINK_DIR:Q}/include/xen
	${CP} ${FILESDIR:Q}/arch-x86_32.h ${BUILDLINK_DIR:Q}/include/xen/
	${CP} ${FILESDIR:Q}/dom0_ops.h ${BUILDLINK_DIR:Q}/include/xen/
	${CP} ${FILESDIR:Q}/event_channel.h ${BUILDLINK_DIR:Q}/include/xen/
	${CP} ${FILESDIR:Q}/sched_ctl.h ${BUILDLINK_DIR:Q}/include/xen/
	${CP} ${FILESDIR:Q}/xen.h ${BUILDLINK_DIR:Q}/include/xen/
	${CP} ${FILESDIR:Q}/xenio.h ${BUILDLINK_DIR:Q}/include/xen

	${MKDIR} ${BUILDLINK_DIR:Q}/include/xen/io
	${CP} ${FILESDIR:Q}/domain_controller.h \
		${BUILDLINK_DIR:Q}/include/xen/io/

.include "../../wip/libxen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
