# $NetBSD: Makefile,v 1.1 2005/12/06 09:09:17 lkundrak Exp $

DISTNAME=		grub
PKGNAME=		grub2-1.91
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://skosi.org/~lkundrak/grub/
#MASTER_SITES=		ftp://alpha.gnu.org/gnu/grub/

MAINTAINER=		lkundrak@skosi.org
HOMEPAGE=		http://www.gnu.org/software/grub/grub.html
COMMENT=		Universal, multiboot compilant GNU boot manager and loader

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS=		gmake bison

# XXX: only on non-linuces!!!
.include "../../wip/libargp/buildlink3.mk"

.include "../../archivers/liblzo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
