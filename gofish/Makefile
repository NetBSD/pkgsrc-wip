# $NetBSD: Makefile,v 1.1.1.1 2005/06/23 13:08:52 emil_s Exp $

DISTNAME=		gofish-1.0
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gofish/}

MAINTAINER=		emil@math.su.se
HOMEPAGE=		http://gofish.sourceforge.net/
COMMENT=		Gopher server

WRKSRC=			${WRKDIR}/gofish
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EXAMPLESDIR=		${PREFIX}/share/examples
RUNTIMEDIR=     	${PREFIX}/var/gopher

GOPHER_USER=    	gopher
GOPHER_GROUP=   	gopher
GOPHER_UID=		30
GOPHER_GID=		30
PKG_GROUPS=     	${GOPHER_GROUP}:${GOPHER_GID}
PKG_USERS=      	${GOPHER_USER}:${GOPHER_GROUP}:${GOPHER_UID}
OWN_DIRS_PERMS= 	${RUNTIMEDIR} ${GOPHER_USER} ${GOPHER_GROUP} 0750

RCD_SCRIPTS=		gopherd

FILES_SUBST+=   	RUNTIMEDIR=${RUNTIMEDIR}
FILES_SUBST+=		PKG_USERS=${PKG_USERS}

post-configure:
	${MV} ${WRKSRC}/gofish.conf ${WRKSRC}/gofish.conf.orig
	${SED}	-e "s/;uid = -1/uid = ${GOPHER_UID}/g"	\
		-e "s/;gid = -1/gid = ${GOPHER_GID}/g"  \
		${WRKSRC}/gofish.conf.orig		\
		> ${WRKSRC}/gofish.conf

.include "../../mk/bsd.pkg.mk"
