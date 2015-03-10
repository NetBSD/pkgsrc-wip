# xxx MesaLib for package 'dri', required by 'xorg-server'
# xxx conditional on dri option? test build w/o dri
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/presentproto/buildlink3.mk"
.include "../../x11/resourceproto/buildlink3.mk"
.include "../../x11/scrnsaverproto/buildlink3.mk"

.include "../../x11/modular-xorg-server/buildlink3.mk"
