# $NetBSD: Makefile,v 1.1.1.1 2004/11/11 12:10:33 poppnk Exp $

DISTNAME=	firefox-wrapper-0.1
CATEGORIES=	www wip
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pancake@phreaker.net
COMMENT=	Firefox binary wrapper

NO_BUILDLINK=	yes
NO_CONFIGURE=	yes
NO_CHECKSUM=	yes
NO_BUILD=	yes

CONF_FILES=	${PKG_SYSCONFDIR}/firefox-wrapper.conf

do-extract:
	@${CP} -Rp ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/firefox ${PREFIX}/bin/firefox
	${INSTALL_SCRIPT} ${WRKSRC}/firefox-wrapper.conf \
		${PKG_SYSCONFDIR}/firefox-wrapper.conf

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	post-patch
SUBST_FILES.etc=	firefox firefox-wrapper.conf
SUBST_SED.etc+=	-e "s,_etc_,${PKG_SYSCONFDIR},g" \
			-e "s,_pfx_,${PREFIX},g"

.include "../../mk/bsd.pkg.mk"
