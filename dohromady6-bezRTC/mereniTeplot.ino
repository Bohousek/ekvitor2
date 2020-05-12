float mereniVzduchu() {
  teplomer.requestTemperaturesByIndex(1); // zmer teplotu venkovniho vzduchu
  return teplomer.getTempCByIndex(1);
}
float mereniVody() {
  teplomer.requestTemperaturesByIndex(0); // zmer teplotu vody v kotli
  return teplomer.getTempCByIndex(0);
}
