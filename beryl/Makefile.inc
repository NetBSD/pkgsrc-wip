# $NetBSD: Makefile.inc,v 1.1 2007/04/25 07:07:57 bsadewitz Exp $
#

CATEGORIES?=	wm
MASTER_SITES=	http://releases.beryl-project.org/${BERYL_VERSION}/
EXTRACT_SUFX?=	.tar.bz2

MAINTAINER?=	blair.sadewitz@gmail.com
HOMEPAGE?=	http://releases.beryl-project.org/

BERYL_VERSION=		0.2.1

GNU_CONFIGURE=		yes

USE_TOOLS+=	pkg-config gmake
