# $NetBSD$

DISTNAME=	dma-0.14
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=corecode/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://github.com/corecode/dma
COMMENT=	The DragonFly Mail Agent
LICENSE=	modified-bsd

BUILD_DEFS+=		VARBASE

PKG_SYSCONFSUBDIR=	dma
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

USE_TOOLS+=	flex byacc

LIBS.Darwin+=	-lresolv
LIBS.Linux+=	-lresolv
LIBS.SunOS+=	-lresolv -lsocket -lnsl

USE_LANGUAGES=		c
# Not documented, but uses // comments.
USE_CC_FEATURES=	c99

.include "../../mk/bsd.prefs.mk"

DMA_GROUP?=	dma
DMA_ROOT_USER?=	dma
DMA_SPOOLDIR=	${VARBASE}/spool/dma

.if ${UNPRIVILEGED:tl} == "yes"
OWN_DIRS_PERMS+=	${DMA_SPOOLDIR} ${UNPRIVILEGED_USER} ${UNPRIVILEGED_GROUP} 0700
.else
OWN_DIRS_PERMS+=	${DMA_SPOOLDIR} ${DMA_ROOT_USER} ${DMA_GROUP} 0770
# Upstream makefile sets sgid/suid but we patched that out.
# dma is sgid for queue access
SPECIAL_PERMS+=		${PREFIX}/libexec/dma \
			${REAL_ROOT_USER} ${DMA_GROUP} 2555
# dma-mbox-create is a suid-root helper for dma, only.   Upstream's makefile
# grants other read permission for unclear reasons; mirror that as not harmful.
SPECIAL_PERMS+=		${PREFIX}/libexec/dma-mbox-create \
			${REAL_ROOT_USER} ${DMA_GROUP} 4554
PKG_GROUPS=		${DMA_GROUP}
PKG_USERS=		${DMA_ROOT_USER}:${DMA_GROUP}
.endif

# dma has awkward getprogname detection; essentially one must define
# HAVE_ on any system without glibc (and getprogname must be present),
# and one should not define it on glibc systems.  We use OPSYS Linux
# as a probably-good-enough proxy for glibc.
# Raised upstream as : https://github.com/corecode/dma/issues/173
.if ${OPSYS} != "Linux"
CFLAGS+=	-DHAVE_GETPROGNAME
.endif
CFLAGS+=	-DHAVE_STRLCPY
CFLAGS+=	-DDMA_GROUP=\"${DMA_GROUP}\"
CFLAGS+=	-DDMA_ROOT_USER=\"${DMA_ROOT_USER}\"

MAKE_ENV+=	CONFDIR=${PKG_SYSCONFDIR}
MAKE_ENV+=	LIBS=${LIBS:Q}

MAKE_FLAGS=	"LIBEXEC=${PREFIX}/libexec"
MAKE_FLAGS+=	"MAN=${PREFIX}/${PKGMANDIR}"
# Work around upstream bug requiring gmake when BSD make is documented
# to work; delete when updating to a release with
# https://github.com/corecode/dma/pull/170.
MAKE_FLAGS+=	version=${PKGVERSION_NOREV}

INSTALLATION_DIRS=	${EGDIR} ${DOCDIR}

CONF_FILES=	${EGDIR}/dma.conf ${PKG_SYSCONFDIR}/dma.conf
CONF_FILES+=	${EGDIR}/auth.conf ${PKG_SYSCONFDIR}/auth.conf

SUBST_CLASSES+=		spool
SUBST_STAGE.spool=	pre-configure
SUBST_FILES.spool=	dma.c dma.conf
SUBST_SED.spool=	-e 's,/var/spool/dma,${DMA_SPOOLDIR},g'
SUBST_NOOP_OK.spool=	yes

SUBST_CLASSES+=		mailer
SUBST_STAGE.mailer=	pre-configure
SUBST_FILES.mailer=	${WRKDIR}/mailer.conf ${WRKDIR}/README.pkgsrc
SUBST_VARS.mailer=	PREFIX

post-extract:
	${CP} ${FILESDIR}/mailer.conf ${WRKDIR}/mailer.conf
	${CP} ${FILESDIR}/README.pkgsrc ${WRKDIR}/README.pkgsrc

post-install:
	${INSTALL_DATA} ${WRKSRC}/dma.conf ${DESTDIR}${EGDIR}/dma.conf
	${INSTALL_DATA} ${WRKSRC}/auth.conf ${DESTDIR}${EGDIR}/auth.conf
	${INSTALL_DATA} ${WRKDIR}/mailer.conf ${DESTDIR}${EGDIR}/mailer.conf
	${INSTALL_DATA} ${WRKDIR}/README.pkgsrc ${DESTDIR}${DOCDIR}/README.pkgsrc

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
