# $NetBSD: Makefile,v 1.9 2007/03/03 15:22:17 shattered Exp $
#

DISTNAME=	qico-0.55si
PKGNAME=	qico-0.55
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qico/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/qico/
COMMENT=	FidoNet mailer

USE_TOOLS+=	gmake
WRKSRC=		${WRKDIR}/qicosi
GNU_CONFIGURE=	yes
MAKE_ENV+=	SH=${SH:Q} AWK=${AWK:Q} MORDA=${QCC:Q}

.if defined(WITH_QCC)
QCC=		1
PLIST_SUBST=	QCC=""
.else
PLIST_SUBST=	QCC="@comment "
.endif

PKG_GROUPS=	news
PKG_USERS=	uucp:news
RCD_SCRIPTS=	qico

EGDIR=			${PREFIX}/share/examples/qico
CONF_FILES_PERMS=	${EGDIR}/qico.conf ${PKG_SYSCONFDIR}/qico.conf \
				uucp news 0644
INSTALLATION_DIRS+=	share/examples/qico

pre-install:
	${INSTALL_DATA} ${WRKSRC}/qico.conf.sample \
		${PREFIX}/share/examples/qico/qico.conf

.include "../../mk/bsd.pkg.mk"
