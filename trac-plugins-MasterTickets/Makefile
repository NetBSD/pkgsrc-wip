# $NetBSD: Makefile,v 1.9 2012/10/07 17:17:46 asau Exp $

UPSTREAM_VERSION=	3.0.2
DISTNAME=	TracMasterTickets-${UPSTREAM_VESRION}
VERSION=	${UPSTREAM_VERSION}.20111224
PKGNAME=	trac-plugins-MasterTickets-${VERSION}
# Force PKGREVISION because git-package by default sets one.
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	# not defined

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/MasterTicketsPlugin
#HOMEPAGE+=	https://github.com/coderanger/trac-mastertickets/
COMMENT=	Ticket dependency plugin for Trac

EGG_NAME=	${DISTNAME}

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac

EGG_NAME=	TracMasterTickets-${UPSTREAM_VERSION}

GIT_REPOSITORIES=		mastertickets
GIT_REPO.mastertickets=		git://github.com/coderanger/trac-mastertickets.git
# It seems that the checkout is of master, not the tag.
GIT_TAG.mastertickets=		af6c1df9
# GIT_MODULE is
#  1) about what the cached git tarball is called
#  2) somehow about more, in that without this line, there is a complaint
#  => (3b) git pull origin master from trac-plugins-MasterTickets .
#  cd: can't cd to trac-plugins-MasterTickets
# But, why is it no per-repository in usage?
GIT_MODULE=		trac-mastertickets

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/trac-mastertickets

#post-extract:
#	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

# MasterTickets uses graphviz directly (rather than via the GraphViz plugin).
# \todo Make this optional.
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
