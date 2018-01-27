# $NetBSD: Makefile,v 1.2 2012/10/03 15:09:57 asau Exp $
#

DISTNAME=	mozldap-6.0.6
CATEGORIES=	devel databases
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/directory/c-sdk/releases/v6.0.6/src/

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	https://wiki.mozilla.org/LDAP_C_SDK
COMMENT=	LDAP C-SDK from Mozilla Project
LICENSE=	gnu-gpl-v1 OR gnu-lgpl-v2.1 OR mpl-1.1

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	pkg-config gmake perl autoconf
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	mozldap.pc.in

CONFIGURE_ARGS+=	--enable-clu
CONFIGURE_ARGS+=	--with-system-svrcore
CONFIGURE_ARGS+=	--with-system-nspr
CONFIGURE_ARGS+=	--with-system-nss

WRKSRC=	${WRKDIR}/${DISTNAME}/mozilla/directory/c-sdk
BINDIR=	${PREFIX}/bin
LIBDIR=	${PREFIX}/lib
EGDIR=	${PREFIX}/share/examples/ldapsdk
INCDIR=	${PREFIX}/include/ldap

HEADERFILES=	ldap-to-be-deprecated.h ldif.h disptmpl.h ldap.h iutil.h \
		lber.h srchpref.h ldap-deprecated.h ldap-standard.h ldappr.h \
		ldap-platform.h ldap-extension.h ldap_ssl.h
CONFFILES=	ldaptemplates.conf ldapsearchprefs.conf ldapfilter.conf \
		ldapfriendly
BINFILES=	ldapsearch ldapcompare ldapdelete ldapmodify ldapcmp \
		ldappasswd
LIBFILES=	libldap60.so libldap60.a libssldap60.so libprldap60.so \
		libldif60.a liblber60.a libldif60.so libiutil60.a

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.  if defined(ABI) && ${ABI} == "64"
CONFIGURE_ARGS+=	--enable-64bit
.  endif
.endif

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "none")
CONFIGURE_ARGS+=        --without-pthreads
.else
CONFIGURE_ARGS+=        --with-pthreads
.include "../../mk/pthread.buildlink3.mk"
.endif

INSTALLATION_DIRS=	bin

pre-configure:
	cd ${WRKSRC} && autoconf

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${INCDIR}
.for i in ${HEADERFILES}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/mozilla/dist/public/ldap/${i:Q} \
		${DESTDIR}${INCDIR}
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
.for i in ${CONFFILES}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/mozilla/dist/etc/${i:Q} \
		${DESTDIR}${EGDIR}
.endfor
.for i in ${BINFILES}
	${INSTALL_PROGRAM} ${WRKDIR}/${DISTNAME}/mozilla/dist/bin/${i:Q} \
	        ${DESTDIR}${BINDIR}/moz${i:Q}
.endfor
.for i in ${LIBFILES}
	${INSTALL_LIB} ${WRKDIR}/${DISTNAME}/mozilla/dist/lib/${i:Q} \
		${DESTDIR}${LIBDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/mozldap.pc ${DESTDIR}${LIBDIR}/pkgconfig

.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../wip/svrcore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
