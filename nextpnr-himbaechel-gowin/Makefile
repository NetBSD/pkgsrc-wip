# $NetBSD: $

COMMENT=	Portable FPGA place and route tool for Gowin devices

NEXTPNR_TARGET=		himbaechel
HIMBAECHEL_UARCH=	gowin
NEXTPNR_TARGET_ARGS=	-DAPYCULA_INSTALL_PREFIX=${PREFIX}
NEXTPNR_TARGET_ARGS+=	-DHIMBAECHEL_UARCH="gowin"
NEXTPNR_TARGET_ARGS+=	-DHIMBAECHEL_SPLIT="ON"

DEPENDS+=	${PYPKGPREFIX}-apycula>=0.23:../../devel/py-apycula

SUBST_CLASSES+=		pypath
SUBST_STAGE.pypath=	post-configure
SUBST_MESSAGE.pypath=	Fixing python path
SUBST_FILES.pypath+=	cmake-pkgsrc-build/himbaechel/uarch/gowin/CMakeFiles/nextpnr-himbaechel-gowin-chipdb.dir/build.make
SUBST_SED.pypath+=	-e 's;${PREFIX}/bin/python;${TOOL_PYTHONBIN};g'

.include "../../devel/nextpnr/nextpnr.mk"
