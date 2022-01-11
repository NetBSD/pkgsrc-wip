# $NetBSD$

DISTNAME=	fetchmail-7.0alpha10
CATEGORIES=	mail
MASTER_SITES=	https://gitlab.com/fetchmail/fetchmail/-/archive/9c011ca4/
SHORT_TAG=	9c011ca4
LONG_TAG=	9c011ca4f688acd0330c7b2635250b2f8cf29b77
# Remnants of failed attempt at using gitlab.mk; it doesn't
# end up trying to fetch the right file / url.
#MASTER_SITES=	${MASTER_SITE_GITLAB:=fetchmail/}
#GITLAB_TAG=	9c011ca4
#GITLAB_TYPE=	tag
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/fetchmail/fetchmail
COMMENT=	Batch mail retrieval/forwarding utility for pop2, pop3, apop, imap
LICENSE=	gnu-gpl-v1 AND gnu-gpl-v2 AND modified-bsd AND public-domain AND gnu-lgpl-v2.1

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-hesiod
CONFIGURE_ENV+=		PYTHON=:
LDFLAGS+=		${CFLAGS}
USE_TOOLS+=		msgfmt tbl
USE_TOOLS+=		autoconf automake
AUTOCONF_REQD=  	2.69

LDFLAGS.Darwin+=	-lresolv
CFLAGS.Darwin+=		-DBIND_8_COMPAT -DHAVE_RESOLV_H

TEST_TARGET=	check

DOCDIR=		${PREFIX}/share/doc/fetchmail
RCD_SCRIPTS=	fetchmail

INSTALLATION_DIRS+=	${DOCDIR}

post-extract:
	${MV} ${WRKDIR}/${PKGBASE}-${SHORT_TAG}-${LONG_TAG} ${WRKSRC}

pre-configure:
	set -e -x; cd ${WRKSRC}; \
	sh autogen.sh

.include "../../devel/gettext-lib/buildlink3.mk"
post-build:
	${MV} ${WRKSRC}/fetchmail.man ${WRKSRC}/fetchmail.man.tbl &&	\
	${TBL} ${WRKSRC}/fetchmail.man.tbl > ${WRKSRC}/fetchmail.man

post-install:
.for f in NEWS OLDNEWS \
		README README.OAUTH2 README.NTLM README.PWMD 		\
		README.SSL README.SSL-SERVER COPYING fetchmail-FAQ.html	\
		fetchmail-features.html design-notes.html
	cd ${WRKSRC} &&							\
	${INSTALL_DATA} ${f} ${DESTDIR}${DOCDIR}
.endfor

#.include "../../wip/mk/gitlab.mk"
.include "../../mk/bsd.pkg.mk"
