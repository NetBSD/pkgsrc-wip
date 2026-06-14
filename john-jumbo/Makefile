# $NetBSD$

DISTNAME=	john-bleeding-jumbo
PKGNAME=	john-jumbo-20260613
DIST_SUBDIR=	${PKGNAME}
CATEGORIES=	security
MASTER_SITES=	-https://github.com/openwall/john/archive/refs/heads/bleeding-jumbo.tar.gz
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.openwall.com/john/
COMMENT=	Unix Password Cracker (community-enhanced version)
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	src

CHECK_PORTABILITY_SKIP=	src/configure src/unused/osx_as_wrapper.sh
CHECK_INTERPRETER_SKIP=	share/john/*.py share/john/*.pl
CONFIGURE_ARGS+=	--disable-opencl

BUILD_TARGET=	default
USE_TOOLS+=	gmake pkg-config perl

INSTALLATION_DIRS=	bin share/john share/john/rules

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/run/john ${DESTDIR}${PREFIX}/bin/john
	${INSTALL_PROGRAM} ${WRKSRC}/run/cprepair ${DESTDIR}${PREFIX}/bin/cprepair
	${INSTALL_PROGRAM} ${WRKSRC}/run/SIPdump ${DESTDIR}${PREFIX}/bin/SIPdump
	${INSTALL_PROGRAM} ${WRKSRC}/run/calc_stat ${DESTDIR}${PREFIX}/bin/calc_stat
	${INSTALL_PROGRAM} ${WRKSRC}/run/genmkvpwd ${DESTDIR}${PREFIX}/bin/genmkvpwd
	${INSTALL_PROGRAM} ${WRKSRC}/run/mkvcalcproba ${DESTDIR}${PREFIX}/bin/mkvcalcproba
	${INSTALL_PROGRAM} ${WRKSRC}/run/raw2dyna ${DESTDIR}${PREFIX}/bin/raw2dyna
	${INSTALL_PROGRAM} ${WRKSRC}/run/tgtsnarf ${DESTDIR}${PREFIX}/bin/tgtsnarf
	${INSTALL_PROGRAM} ${WRKSRC}/run/vncpcap2john ${DESTDIR}${PREFIX}/bin/vncpcap2john
	${INSTALL_PROGRAM} ${WRKSRC}/run/wpapcap2john ${DESTDIR}${PREFIX}/bin/wpapcap2john
	${INSTALL_PROGRAM} ${WRKSRC}/run/eapmd5tojohn ${DESTDIR}${PREFIX}/bin/eapmd5tojohn
	${INSTALL_PROGRAM} ${WRKSRC}/run/hccap2john ${DESTDIR}${PREFIX}/bin/hccap2john
	${INSTALL_PROGRAM} ${WRKSRC}/run/racf2john ${DESTDIR}${PREFIX}/bin/racf2john
	${INSTALL_PROGRAM} ${WRKSRC}/run/keepass2john ${DESTDIR}${PREFIX}/bin/keepass2john
	${INSTALL_PROGRAM} ${WRKSRC}/run/bitlocker2john ${DESTDIR}${PREFIX}/bin/bitlocker2john
	${INSTALL_PROGRAM} ${WRKSRC}/run/dmg2john ${DESTDIR}${PREFIX}/bin/dmg2john
	${INSTALL_PROGRAM} ${WRKSRC}/run/putty2john ${DESTDIR}${PREFIX}/bin/putty2john
	${INSTALL_PROGRAM} ${WRKSRC}/run/uaf2john ${DESTDIR}${PREFIX}/bin/uaf2john
.for l in unshadow unafs unique undrop rar2john zip2john gpg2john base64conv
	${LN} -sf john ${DESTDIR}${PREFIX}/bin/${l}
.endfor
	${INSTALL_DATA} ${WRKSRC}/run/*.conf ${DESTDIR}${PREFIX}/share/john/
	${INSTALL_DATA} ${WRKSRC}/run/*.chr ${DESTDIR}${PREFIX}/share/john/
	${INSTALL_DATA} ${WRKSRC}/run/password.lst ${DESTDIR}${PREFIX}/share/john/
	${INSTALL_DATA} ${WRKSRC}/run/rules/* ${DESTDIR}${PREFIX}/share/john/rules/
	${INSTALL_SCRIPT} ${WRKSRC}/run/*.pl ${DESTDIR}${PREFIX}/share/john/
	${INSTALL_SCRIPT} ${WRKSRC}/run/*.py ${DESTDIR}${PREFIX}/share/john/

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
