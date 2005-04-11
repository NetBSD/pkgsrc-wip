# $NetBSD: Makefile,v 1.10 2005/04/11 21:14:11 tvierling Exp $

DISTNAME=		mutt-1.5.4i
WRKSRC=			${WRKDIR}/${DISTNAME:C/i$$//}
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.mutt.org/mutt/devel/ \
			ftp://ftp.stealth.net/pub/mirrors/ftp.mutt.org/pub/mutt/devel/ \
			ftp://gd.tuwien.ac.at/infosys/mail/mutt/devel/ \
			ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/devel/

MAINTAINER=		charlie@rubberduck.com
HOMEPAGE=		http://www.mutt.org/
COMMENT=		Text-based MIME mail client with PGP support

# for nntp patch
DISTFILES=  ${DISTNAME}${EXTRACT_SUFX}

CONFLICTS+=		mutt-[0-9]*

BUILD_USES_MSGFMT=	yes

USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR} \
			--with-docdir=${PREFIX}/share/doc/mutt \
			--without-included-gettext \
			--enable-pop --enable-imap

REPLACE_PERL=		${WRKSRC}/smime_keys.pl

LDFLAGS+=		${_STRIPFLAG_CC}

.include "../../mk/bsd.prefs.mk"

.if ${MUTT_USE_SLANG} == YES
. include "../../devel/libslang/buildlink3.mk"
CONFIGURE_ARGS+=	--with-slang=${BUILDLINK_PREFIX.libslang}
.else
. if ${MUTT_USE_NCURSES} == YES
USE_NCURSES=		yes
. endif
. include "../../devel/ncurses/buildlink3.mk"
CONFIGURE_ARGS+=	--with-curses=${BUILDLINK_PREFIX.ncurses}
.endif

.if defined(MUTT_USE_NNTP) && ${MUTT_USE_NNTP} == YES
PATCHFILES+=${NNTP_PATCH}
PATCH_DIST_STRIP= -p1
NNTP_PATCH=patch-1.5.4.vvv.nntp.gz
SITES_${NNTP_PATCH}=http://mutt.org.ua/download/mutt-1.5.4/

CONFIGURE_ARGS+=--enable-nntp

pre-install:
	${PATCH} -d ${WRKSRC} < ${FILESDIR}/no_smime

.endif

.if defined(MUTT_USE_DATE_CONDITIONAL) && ${MUTT_USE_DATE_CONDITIONAL} == YES
PATCHFILES+= patch-1.5.1.ats.date_conditional.1 patch-1.5.1.dgc.deepif.1
DATE_CONDITIONAL=patch-1.5.1.ats.date_conditional.1
DEEPIF=patch-1.5.1.dgc.deepif.1
SITES_${DATE_CONDITIONAL}=http://www.schrab.com/aaron/mutt/
SITES_${DEEPIF}=http://home.uchicago.edu/~dgc/sw/mutt/

MESSAGE_SRC+=	${.CURDIR}/MESSAGE.date_conditional
.endif

# There seems to be a problem using NetBSD's /bin/sh, so use /bin/ksh instead.
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-exec-shell=/bin/ksh
.endif

.if ${MUTT_USE_SSL} == YES
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if defined(USE_SASL2) && ${USE_SASL2} == "YES"
.include "../../security/cyrus-sasl2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sasl2=${BUILDLINK_PREFIX.cyrus-sasl2}
.endif

BUILD_DEFS+=		MUTT_USE_DATE_CONDITIONAL MUTT_USE_NCURSES
BUILD_DEFS+=		MUTT_USE_NNTP MUTT_USE_SLANG MUTT_USE_SSL
BUILD_DEFS+=		USE_SASL USE_SASL2

EGDIR=			${PREFIX}/share/examples/mutt
CONF_FILES=		${EGDIR}/Muttrc ${PKG_SYSCONFDIR}/Muttrc
SUPPORT_FILES=		${EGDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types

post-extract:
	${MV} ${WRKSRC}/doc/mutt.man ${WRKSRC}/doc/mutt.man.in
	${SED} -e "s|@PREFIX@|${PREFIX}|g" \
	       -e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g" \
	       < ${WRKSRC}/doc/mutt.man.in > ${WRKSRC}/doc/mutt.man

post-install:
	${CP} ${WRKSRC}/smime_keys ${PREFIX}/bin
	${LN} -s ${EGDIR} ${PREFIX}/share/doc/mutt/samples

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
