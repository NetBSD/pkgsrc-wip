# $NetBSD: Makefile,v 1.1.1.1 2005/06/22 10:11:49 marttikuparinen Exp $
#

DISTNAME=		vm-tools-0.1.6
CATEGORIES=		sysutils
MASTER_SITES=		http://www.cs.utexas.edu/users/aliguori/vm-tools/

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://www.cs.utexas.edu/users/aliguori/vm-tools/
COMMENT=		Lightweight management framework for Xen

ONLY_FOR_PLATFORM=	NetBSD-*-i386

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake

pre-build:
	${MKDIR} ${BUILDLINK_DIR}/include/xen
	${CP} ${FILESDIR}/arch-x86_32.h ${BUILDLINK_DIR}/include/xen/
	${CP} ${FILESDIR}/dom0_ops.h ${BUILDLINK_DIR}/include/xen/
	${CP} ${FILESDIR}/event_channel.h ${BUILDLINK_DIR}/include/xen/
	${CP} ${FILESDIR}/sched_ctl.h ${BUILDLINK_DIR}/include/xen/
	${CP} ${FILESDIR}/xen.h ${BUILDLINK_DIR}/include/xen/

	${MKDIR} ${BUILDLINK_DIR}/include/xen/io
	${CP} ${FILESDIR}/domain_controller.h ${BUILDLINK_DIR}/include/xen/io/

.include "../../wip/libxen/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
