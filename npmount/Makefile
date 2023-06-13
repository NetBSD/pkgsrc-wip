# $NetBSD$

DISTNAME=	npmount-0.1.1.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=outpaddling/}
GITHUB_TAG=	61db68f8c8f14eeb7798b06578a34512c1a5574f

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/outpaddling/npmount
COMMENT=	Command line tool for non-privileged [un]mount
LICENSE=	2-clause-bsd

EGDIR=		${PREFIX}/share/examples/npmount
CONF_FILES=	${EGDIR}/npmount.conf.sample ${PREFIX}/etc/npmount.conf

SPECIAL_PERMS+=		bin/npmount ${SETUID_ROOT_PERMS}
INSTALLATION_DIRS=	bin

post-install:
	${MKDIR} ${DESTDIR}${EGDIR}
	${MV} ${DESTDIR}${PREFIX}/etc/npmount.conf.sample ${DESTDIR}${EGDIR}

.include "../../wip/libxtend/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
