# $NetBSD: Makefile,v 1.14 2015/08/04 20:04:16 thomasklausner Exp $

UPSTREAM_VERSION=	3.90
DISTNAME=		TracMasterTickets-${UPSTREAM_VERSION}
VERSION=		${UPSTREAM_VERSION}.${SVN_TAG.mastertickets}
PKGNAME=		trac-plugins-MasterTickets-${VERSION}
# PKGREVISION must exist for svn, or else it will get a date
PKGREVISION=
CATEGORIES=		www
MASTER_SITES=		# not defined

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://trac-hacks.org/wiki/MasterTicketsPlugin
COMMENT=	Ticket dependency plugin for Trac
LICENSE=	modified-bsd

DEPENDS+=	trac>=1.0:../../www/trac

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 3.0.4/r12946

SVN_REPOSITORIES=		mastertickets
SVN_REPO.mastertickets=		https://trac-hacks.org/svn/masterticketsplugin/trunk

# Upstream has labeled 4.0.0dev at r14695.  Since it appears release
# are not forthcoming, I have adopted 3.90.rSVN to have version
# numbers that can increase while staying under 4.
SVN_TAG.mastertickets=		14695

# TODO: do this more cleanly
EGG_INFODIR=		TracMasterTickets-4.0.0.dev0-py2.7.egg-info

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/mastertickets

#post-extract:
#	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

# MasterTickets uses graphviz directly (rather than via the GraphViz plugin).
# \todo Make this optional.
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
