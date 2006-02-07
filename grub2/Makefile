# $NetBSD: Makefile,v 1.5 2006/02/07 08:14:10 lkundrak Exp $

DISTNAME=		grub2
PKGNAME=		grub2-${GRUB_VERSION}
CATEGORIES=		sysutils
MASTER_SITES=		# not defined

MAINTAINER=		lkundrak@skosi.org
HOMEPAGE=		http://www.gnu.org/software/grub/grub.html
COMMENT=		Universal multiboot compilant GNU boot manager and loader

CVS_REPOSITORIES=	grub2
CVS_ROOT.grub2=		:pserver:anonymous:@cvs.savannah.gnu.org:/sources/grub
CVS_MODULE.grub2=	grub2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake bison

CONFLICTS=		grub-*
ONLY_FOR_PLATFORM=	*-*-i386
# XXX: Linux-*-powerpc and others

.include "../../wip/grub2/version.mk"

.include "../../wip/libargp/buildlink3.mk"
.include "../../archivers/liblzo/buildlink3.mk"
.include "../../devel/binutils/buildlink3.mk"

.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
